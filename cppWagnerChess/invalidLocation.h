class InvalidLocation{

  string message;

public:
  InvalidLocation():message{"NOT A VALID SET OF LOCATIONS!"}{}
  string print(void){return message;}
};
