
// cihazın kaç kez açılıp kapandığı buraya kaydedilebilir.
#include <Preferences.h>

#define LED 4
String ssid1;
String password1;

Preferences preferences;
const char *ssid = "REPLACE_WITH_YOUR_SSID";
const char *password = "REPLACE_WITH_YOUR_PASSWORDaaaaaaaaasdbjrkbgjkrwehgwjkrgwjrgjwl";

void setup()
{
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    Serial.println();

    preferences.begin("my-app", false); // false -> okuma ve yazma true->okuma

    // Remove all preferences under the opened namespace
    // preferences.clear();

    // Or remove the counter key only
    // preferences.remove("counter");

    // Get the counter value, if the key does not exist, return a default value of 0
    // Note: Key name is limited to 15 chars.
    preferences.putString("ssid", ssid);
    preferences.putString("password", password);
}

void loop()
{
    ssid1 = preferences.getString("ssid", "");
    password1 = preferences.getString("password", "");
    Serial.println(ssid1);
    Serial.println(password1);
    delay(5000);
}