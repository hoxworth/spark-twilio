#include "twilio.h"

// Need account sid, auth token, from number?
Twilio::Twilio(char *aSid, char *aToken) {
    accountSid = new String(aSid);
    authToken = new String(aToken);
}

Twilio::~Twilio() {
    delete accountSid;
    delete authToken;
}

void Twilio::message(char *toNumber, char *fromNumber, char *body) {
    message(toNumber, fromNumber, body, "");
}

void Twilio::message(char *toNumber, char *fromNumber, char *body, char * mediaUrl) {
    String json = String("{\"ACCT\":\"");
    String escapedBody = String(body);
    escapedBody.replace("\"", "\\\"");

    json.concat(*accountSid);
    json.concat(String("\",\"TOKEN\":\""));
    json.concat(*authToken);
    json.concat(String("\",\"TO\":\""));
    json.concat(String(toNumber));
    json.concat(String("\",\"FROM\":\""));
    json.concat(String(fromNumber));
    json.concat(String("\",\"BODY\":\""));
    json.concat(String(body));
    json.concat(String("\",\"MEDIA\":\""));
    json.concat(String(mediaUrl));
    json.concat(String("\"}"));
    
    Spark.publish("Twilio/message", json.c_str(), 60, PRIVATE);
}
