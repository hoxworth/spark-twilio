#include "twilio.h"

Twilio twilioClient = Twilio();

/**
 *
 * You can call the function "twilio" on your device to send texts, or try
 * incorporating it into your firmware in other places!
 *
 */
int twilio(String command) {
	twilioClient.message(command.c_str());
	return 1;
}



void setup() {
	twilioClient.message("I'm alive! call twilio fn to send texts");
	Spark.function("twilio", twilio);
}

void loop(){
	//don't send texts in your loop unless you're very careful about spacing them out! 
}


