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
	  "north"     : "market_northeast",
	  "west"      : "market_southwest",
	  "northwest" : "market_northwest",
	]));
}
