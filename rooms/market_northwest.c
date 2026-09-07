inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");
  set_brief("Skeleton Room");
  set_long("This is a skeleton room.");
  set_weather(1);

  set_exits(([
	  "north"     : "market_northwest",
	  "east"      : "market_southeast",
	  "west"      : "street_03",
	  "northeast" : "market_northeast",
	]));
  
}
