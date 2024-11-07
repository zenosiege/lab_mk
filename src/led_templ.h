template<int pin>
class LED {
    public:

        LED() {};

        static void init() { pinMode(pin, OUTPUT); }
        static void on() { digitalWrite(pin, HIGH); }
        static void off() { digitalWrite(pin, LOW); }
}; // class

//наш ргб-диод катнодно-управляемый

enum class Connection_type {anode_driven, cathode_driven};

class Anode_driven {};
class Cathode_driven {};

template<int pin, int rpin, int gpin, int bpin, typename Conn_type>
class RGB_LED {
    public:

        RGB_LED() = delete; //ПАМЯТЬ МНЕ ОСВОБОДИ

        
        static void init() { pinMode(pin, OUTPUT); pinMode(rpin, OUTPUT); pinMode(gpin, OUTPUT); pinMode(bpin, OUTPUT);}

        //is_same не работает из-за своего компилятора и своего набора заголовочных файлов

        static void on() { 
            if constexpr (std::is_same<Anode_driven, Conn_type>)
                {digitalWrite(pin, HIGH);}
            if constexpr (std::is_same<Cathode_driven, Conn_type>)
                {digitalWrite(pin, LOW);}   
        }

        static void off() { 
            if constexpr (std::is_same<Anode_driven, Conn_type>)
                {digitalWrite(pin, LOW);}
            if constexpr (std::is_same<Cathode_driven, Conn_type>)
                {digitalWrite(pin, HIGH);}   
        }


        static void analogColor(unsigned int rVal, unsigned int gVal, unsigned int bVal) {
            analogWrite(rpin, rVal); 
            analogWrite(gpin, gVal); 
            analogWrite(bpin, bVal);
        }

        static void clrRGB(char color) {
            switch (color) {
                case 'r':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, HIGH);
                    break;
                case 'g':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, HIGH);
                    break;
                case 'b':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, LOW);
                    break;
                case 'w':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, LOW);
                    break;
                default:
                    Serial.print('che durak tak delat?');
                    break;
            }
        }

        static void staticRGBlight (){
            unsigned int r = 255;
            unsigned int g = 0;
            unsigned int b = 0;

            int x = 1;

            analogColor(r, g, b);

            while(b != 255) {
                b += 1;
                analogColor(r, g, b);
                delay(x);
            }

            while(r != 0) {
                r -= 1;
                analogColor(r, g, b);
                delay(x);
            }

            while(g != 255) {
                g += 1;
                analogColor(r, g, b);
                delay(x);
            }

            while(b != 0) {
                b -= 1;
                analogColor(r, g, b);
                delay(x);
            }

            while(r != 255) {
                r += 1;
                analogColor(r, g, b);
                delay(x);
            }

            while(g != 0) {
                g -= 1;
                analogColor(r, g, b);
                delay(x);
            }
        }
        /*
        static void clrRGBoff(char color) {
            switch (color) {
                case 'r':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, LOW);
                    break;
                case 'g':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, LOW);
                    break;
                case 'b':
                    digitalWrite(rpin, LOW); 
                    digitalWrite(gpin, LOW); 
                    digitalWrite(bpin, HIGH);
                    break;
                case 'w':
                    digitalWrite(rpin, HIGH); 
                    digitalWrite(gpin, HIGH); 
                    digitalWrite(bpin, HIGH);
                    break;
                default:
                    Serial.print('che durak tak delat?');
                    break;
            }
            
        }*/
}; // class

void delay_s(unsigned int s){
    delay(s * 1000);
}