inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");

	set_brief("Southeast Corner of Zayaville Marketplace");

	set_long(
	  "The southeast corner of Zayaville's cobblestone marketplace lies "
	  "here. Weathered shopfronts face the square, which continues north "
	  "and west."
	);

  set_weather(1);

  set_exits(([
	  "north"     : "market_northeast",
	  "west"      : "market_southwest",
	  "northwest" : "market_northwest",
	]));
}
