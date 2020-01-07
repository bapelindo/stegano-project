Steganography
===================

### Installation

1. <b>Install Open-CV : </b>
Make sure that latest version of Open-CV is installed on your machine.
Refer <a href="https://github.com/jayrambhia/Install-OpenCV">this</a> repository for installation.

2. <b>Compile the program : </b>
  ```
  $ cd ImageSteganography
  $ chmod +x make_encode
  $ chmod +x make_decode
  $ ./make_encode
  $ ./make_decode
  ```

### Running the Program

1. Place your normal .png image in the Images directory.
2. Place your .txt file with the secret message in TextFiles directory.
3. How to Encode the message

  ```
  $ ./encode 'Where_Folder_image'/input_image.png 'Where_Folder_Text'/text_file.txt Images/output_image.png
  ```
  A new image will be created in your Images directory with the secret message hidden in it.

4. How to Decode the message

  ```
  $ ./decode 'Where_Folder_image'/output_image.png
  ```
  The hidden message will be displayed on your console.
