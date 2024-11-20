template<int signal_pin>
class PhotoSensor {
    public:

        PhotoSensor() = delete;
        // не требуется инициализировать фоторезистор
        // static void init() { pinMode(signal_pin, INPUT); }

        static int Read() { 
                return analogRead(signal_pin); 
            }
        
        static void PrintRead() { 
                Serial.println(analogRead(signal_pin)); 
            }
        
}; // class