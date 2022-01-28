class CustomString {
    public:
        // default constructor
        CustomString();
        CustomString(const char* input_value);
        // copy constructor
        CustomString(const CustomString & other);
        // move constructor
        CustomString(CustomString&& other);

        // + operator overloading
        CustomString operator + (CustomString const & obj);

        // destructor
        ~CustomString();

        char*  string_value;
        int string_size;    
};
