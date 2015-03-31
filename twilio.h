#ifndef SPARK_TWILIO_H
#define SPARK_TWILIO_H

#include "application.h"

class Twilio {
  public:
  	Twilio();
  	~Twilio();

    void message(char *toNumber, char *fromNumber, char *body);
  	void message(char *toNumber, char *fromNumber, char *body, char * mediaUrl);

  private:
  	String *accountSid;
  	String *authToken;
};

#endif // SPARK_TWILIO_H