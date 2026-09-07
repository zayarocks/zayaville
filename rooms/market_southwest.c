inherit OUTDOOR_ROOM;

void setup()
{
	set_area("zayaville");

	set_brief("Southwest Corner of Zayaville Marketplace");

	set_long(
		"The southwest corner of Zayaville's cobblestone marketplace opens "
		"here. A village road leaves the square to the west, while the "
		"marketplace continues north and east."
	);

	set_weather(1);

	set_exits(([
		"north"     : "market_northwest",
		"east"      : "market_southeast",
		"west"      : "street_03",
		"northeast" : "market_northeast",
	]));
}
