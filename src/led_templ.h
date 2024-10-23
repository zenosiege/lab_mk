template<int pin>
class LED {
    public:

        LED() {};

        static void init() { pinMode(pin, OUTPUT); }
        static void on() { digitalWrite(pin, HIGH); }
        static void off() { digitalWrite(pin, LOW); }
}; // class

void delay_s(unsigned int s){
    delay(s * 1000);
}