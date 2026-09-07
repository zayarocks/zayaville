inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");

	set_brief("Northeast Corner of Zayaville Marketplace");

	set_long(
	  "The northeast corner of Zayaville's cobblestone marketplace is "
	  "bordered by old village shops. The marketplace continues south "
	  "and west."
	);

  set_weather(1);

	set_exits(([
	  "south"     : "market_southeast",
	  "west"      : "market_northwest",
	  "southwest" : "market_southwest",
	]));
}
