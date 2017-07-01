// Quiz Button system where the first person to press the button gets to answer, their button lights up if they are first.
//  
// 
// Version 0.1

int MASTER_BUTTON = 53;

class Button {
  public:
    int input;
    int output;
    int detector;
    Button(int in, int out, int detect);
    ~Button();
};

Button::Button(int in, int out, int detect) {
  input = in;
  output = out;
  detector = detect;
}

Button::~Button(void) {}

Button buttons[] = {
    Button(22, 24, 26),
    Button(23, 25, 27),
    Button(28, 30, 32),
    Button(29, 31, 33),
    Button(34, 36, 38),
    Button(35, 37, 39),
    Button(40, 42, 44),
    Button(41, 43, 45)
};

void setup() {
  pinMode(MASTER_BUTTON, INPUT);
  
  for (int i = 0; i < sizeof(buttons); i++) {
    pinMode(buttons[i].input, INPUT);
    pinMode(buttons[i].detector, INPUT);
    pinMode(buttons[i].output, OUTPUT);
  }
}

bool accept_input = true;

void loop() {
  if (accept_input) {
    for (int i = 0; i < sizeof(buttons); i++) {
      if (digitalRead(buttons[i].detector) == HIGH) {
        if (digitalRead(buttons[i].input) == HIGH) {
          accept_input = false;
          digitalWrite(buttons[i].output, HIGH);
        }
      }
    }
  } else if (digitalRead(MASTER_BUTTON) == HIGH) {
    for (int i = 0; i < sizeof(buttons); i++) {
      digitalWrite(buttons[i].output, LOW);
      accept_input = true;
    }
  }
}















