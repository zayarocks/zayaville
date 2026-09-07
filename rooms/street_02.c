inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Simple Village Road");

  set_long(
    "This is a little way along the path to the village of "
    "Zayaville. The path continues northeast toward the rickety "
    "buildings of the market square. To the southwest, the path "
    "winds away from what passes as civilization here."
  );

  set_weather(1);

  set_exits(([
    "southwest" : "street_01",
  ]));
}