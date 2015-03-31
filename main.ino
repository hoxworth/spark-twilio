#include "twilio.h"

Twilio twilioClient = Twilio();

/**
 *
 * You can call the function "twilio" on your device to send texts, or try
 * incorporating it into your firmware in other places!
 *
 */
int twilio(String command) {
	twilioClient.message("+14107224127", "+15103355285", command.c_str());
	return 1;
}


void setup() {
	Spark.function("twilio", twilio);

	twilioClient.message("+14107224127", "+15103355285", 
		"I'm alive! call twilio fn to send texts");
}

void loop(){
	//don't send texts in your loop unless you're very careful about spacing them out! 
}


