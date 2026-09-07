inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");
  set_brief("Skeleton Room");
  set_long("This is a skeleton room.");
  set_weather(1);

  set_exits(([
	  "north"     : "market_northeast",
	  "west"      : "market_southwest",
	  "northwest" : "market_northwest",
	]));
}
