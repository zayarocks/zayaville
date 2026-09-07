inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");
  set_brief("Skeleton Room");
  set_long("This is a skeleton room.");
  set_weather(1);
 
  set_exits(([
    "east"      : "market_southwest",
    "southwest" : "street_02",
  ]));

}
