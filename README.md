# web_serial

After you finish writing a web page that speesh audio to text, the web-serial code is added in the JavaScript section, to make the web page a port to the Arduino board.

-The first step is to open a serial port using:
- document.querySelector('input').addEventListener('click', async () => {
- const port = await navigator.serial.requestPort();
-  await port.open({ baudRate: 9600 });
-  });

![صورة11](https://user-images.githubusercontent.com/109717135/183350969-1665f36b-1a82-4b03-ab5a-800d33296bb2.png)

-To read from a serial port:
- const textDecoder = new TextDecoderStream();
- const readableStreamClosed = port.readable.pipeTo(textDecoder.writable);
- const reader = textDecoder.readable.getReader();
- 
- while (true) {
- const { value, done } = await reader.read();
- if (done) {
- reader.releaseLock();
- break;
- }
- console.log(value);

-for writing to the serial port:
  - const textEncoder = new TextEncoderStream();
  - const writableStreamClosed = textEncoder.readable.pipeTo(port.writable);
  - const writer = textEncoder.writable.getWriter();
  - await writer.write("يمين", "يسار");

-finally close the serial port:
- await port.close();
