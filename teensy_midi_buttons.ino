/* MIDI to ATEM Scene switcher

   You must select MIDI from the "Tools > USB Type" menu

   To view the raw MIDI data on Linux: aseqdump -p "Teensy MIDI"
*/

// the MIDI channel number to send messages
const int channel = 1;

void setup() {
  // configure the needed Pins as Output
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);

  // configure method as Event Handler for NoteOn Events
  usbMIDI.setHandleNoteOn(OnNoteOn);
}

void OnNoteOn(byte channel, byte note, byte velocity) {
  // print some Debug Information
  Serial.print("Note On, ch=");
  Serial.print(channel, DEC);
  Serial.print(", note=");
  Serial.print(note, DEC);
  Serial.print(", velocity=");
  Serial.print(velocity, DEC);
  Serial.println();

  // toggle the Pins for 200 milliseconds
  if(note == 60) {
    digitalWrite(A5, HIGH);
    delay(200);
    digitalWrite(A5, LOW);
  } else if(note == 61) {
    digitalWrite(A4, HIGH);
    delay(200);
    digitalWrite(A4, LOW);
  } else if(note == 62) {
    digitalWrite(A3, HIGH);
    delay(200);
    digitalWrite(A3, LOW);
  } else if(note == 63) {
    digitalWrite(A2, HIGH);
    delay(200);
    digitalWrite(A2, LOW);
  } else if(note == 64) {
    digitalWrite(A1, HIGH);
    delay(200);
    digitalWrite(A1, LOW);
  } 
}


void loop() {
  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}

