inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Zayaville Marketplace");

  set_long(
    "A broad cobblestone marketplace opens here beneath the sky. "
    "Weathered buildings surround the square, their shopfronts facing "
    "an open space where merchants and villagers gather."
  );

  set_weather(1);

  set_exits(([
	  "north"     : "market_northwest",
	  "east"      : "market_southeast",
	  "west"      : "street_03",
	  "northeast" : "market_northeast",
	]));
}
