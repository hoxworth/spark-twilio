#ifndef SPARK_TWILIO_H
#define SPARK_TWILIO_H

#include "application.h"

class Twilio {
  public:
  	Twilio();
  	~Twilio();

	void message(const char *body);
    void message(const char *toNumber, const char *fromNumber, const char *body);
  	void message(const char *toNumber, const char *fromNumber, const char *body, const char * mediaUrl);

  private:
  	String *accountSid;
  	String *authToken;
};

#endif // SPARK_TWILIO_H