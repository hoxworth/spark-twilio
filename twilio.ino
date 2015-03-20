#include "twilio.h"

Twilio twilioClient = Twilio("MY_ACCOUNT_SID", "MY_TOKEN");

int twilio(String command);

void setup() {
	Spark.function("twilio", twilio);
}

void loop(){
}

int twilio(String command) {
	twilioClient.message("+14107224127", "+15103355285", "Hello there!");
}


