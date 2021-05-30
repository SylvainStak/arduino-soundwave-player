#include "notes.h" // pitches
#include "tetris.h" // melody

int speakerPin = 8; // Pin connected to the speaker in arduino
int tempo = 200;
int notes = sizeof(melody)/sizeof(melody[0])/2;
int wholenote = 240000/tempo;
int divider = 0;
int noteDuration = 0;

void setup() {
  //loop through all notes
  for (int thisNote = 0; thisNote < notes*2; thisNote = thisNote+2) {
    // Get the note duration time divider
    divider = melody[thisNote+1];
    // Determine whether its a dotted note or not, multiplying times 1.5 the note duration for dotted notes
    noteDuration = divider<0?((wholenote)/abs(divider))*1.5:(wholenote)/divider;
    // Play the note for 90% of the full duration time so they do not collapse
    tone(speakerPin, melody[thisNote], noteDuration*0.90);
    // Let the note play for the calculated time
    delay(noteDuration);
    // Stop the waveform after the note has been fully played
    noTone(speakerPin);
  }
}

void loop() {}
