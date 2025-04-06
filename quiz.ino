const int buttonA = 2;
const int buttonB = 3;
const int buttonC = 4;
const int ledCorrect = 5;
const int ledWrong = 6;

int score = 0;
int currentQuestion = 0;

String questions[] = {
  "Q1: Capital of India?\nA) Mumbai\nB) Delhi\nC) Kolkata",
  "Q2: Largest planet?\nA) Earth\nB) Jupiter\nC) Venus",
  "Q3: Who wrote Ramayana?\nA) Tulsidas\nB) Valmiki\nC) Ved Vyas"
};

char correctAnswers[] = {'B', 'B', 'B'};

void setup() {
  Serial.begin(9600);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonC, INPUT_PULLUP);
  pinMode(ledCorrect, OUTPUT);
  pinMode(ledWrong, OUTPUT);
  askQuestion();
}

void loop() {
  if (digitalRead(buttonA) == LOW) checkAnswer('A');
  if (digitalRead(buttonB) == LOW) checkAnswer('B');
  if (digitalRead(buttonC) == LOW) checkAnswer('C');
  delay(300);
}

void askQuestion() {
  Serial.println(questions[currentQuestion]);
}

void checkAnswer(char answer) {
  if (answer == correctAnswers[currentQuestion]) {
    digitalWrite(ledCorrect, HIGH);
    delay(500);
    digitalWrite(ledCorrect, LOW);
    score++;
    Serial.println("Correct! 🎉");
  } else {
    digitalWrite(ledWrong, HIGH);
    delay(500);
    digitalWrite(ledWrong, LOW);
    Serial.println("Wrong! ❌");
  }

  currentQuestion++;
  if (currentQuestion < 3) {
    askQuestion();
  } else {
    Serial.print("Game Over! Your score: ");
    Serial.println(score);
    while (1); // End of quiz
  }
}
