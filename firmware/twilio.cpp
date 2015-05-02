#include "twilio.h"
#include "application.h"

Twilio::Twilio() {

}

// This will work better when the maximum publish size limits are increased,
// in the meantime, be sure to store ACCT and TOKEN in your webhook definiton
// Twilio::Twilio(char *aSid, char *aToken) {
//     accountSid = new String(aSid);
//     authToken = new String(aToken);
// }

Twilio::~Twilio() {
    delete accountSid;
    delete authToken;
}

void Twilio::message(const char *body) {
    message(NULL, NULL, body, NULL);
}

void Twilio::message(const char *toNumber, const char *fromNumber, const char *body) {
    message(toNumber, fromNumber, body, "");
}

void Twilio::message(const char *toNumber, const char *fromNumber, const char *body, const char *mediaUrl) {
    String escapedBody = String(body);
    escapedBody.replace("\"", "\\\"");

    String json = String("{"); 


    json.concat(String("\"BODY\":\"") + String(escapedBody)+ String("\""));

    //TODO: uncomment when max publish length is increased
    // json.concat(String("\"TO\":\"") + String(toNumber)+ String("\","));    
    //
    // json.concat(String("\"FROM\":\"") + String(fromNumber)+ String("\","));
    //
    // if (this->accountSid != NULL) {
    //     json.concat(String(",\"ACCT\":\"") + String(*this->accountSid) + String("\""));
    // }
    //
    // if (this->authToken != NULL) {
    //     json.concat(String(",\"TOKEN\":\"") + String(*this->authToken) + String("\","));
    // }
    //
    // if (mediaUrl != NULL) {
    //     json.concat(String(",\"MEDIA\":\"") + String(mediaUrl) + String("\""));
    // }

    json.concat("}");

    // make sure you're not calling this more than once per second,
    // and checkout Twilio pricing here: 
    //  https://www.twilio.com/user/account/usage/primary
    //
    Spark.publish("Twilio/message", json.c_str(), 60, PRIVATE);
}

