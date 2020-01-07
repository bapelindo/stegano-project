#include <iostream>
#include <fstream>
#include <highgui.h>
using namespace std;
using namespace cv;
bool isBitSet(char ch, int pos) {
	// 7 6 5 4 3 2 1 0
	ch = ch >> pos;
	if(ch & 1)
		return true;
	return false;
}

int main(int argc, char** argv) {
	if(argc != 4) {
		cout << "Arguments Error" << "\n";
		exit(-1);
	}
	Mat image = imread(argv[1]);
	if(image.empty()) {
		cout << "Image Error\n";
		exit(-1);
	}
	ifstream file(argv[2]);
	if(!file.is_open()) {
		cout << "File Error\n";
		exit(-1);
	}
	char ch;
	file.get(ch);
	int bit_count = 0;
	bool last_null_char = false;
	bool encoded = false;

	for(int row=0; row < image.rows; row++) {
		for(int col=0; col < image.cols; col++) {
			for(int color=0; color < 3; color++) {
				Vec3b pixel = image.at<Vec3b>(Point(row,col));

				if(isBitSet(ch,7-bit_count))
					pixel.val[color] |= 1;
				else
					pixel.val[color] &= ~1;

				image.at<Vec3b>(Point(row,col)) = pixel;

				bit_count++;

				if(last_null_char && bit_count == 8) {
					encoded  = true;
					goto OUT;
				}

				if(bit_count == 8) {
					bit_count = 0;
					file.get(ch);
					if(file.eof()) {
						last_null_char = true;
						ch = '\0';
					}
				}

			}
		}
	}
	OUT:;

	if(!encoded) {
		cout << "Message too big. Try with larger image.\n";
		exit(-1);
	}
	imwrite(argv[3],image);

    return 0;
}
