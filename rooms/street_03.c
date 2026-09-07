inherit OUTDOOR_ROOM;

void setup()
{
	set_area("zayaville");
	set_brief("Entrance to Zayaville Marketplace");

	set_long(
		"The village road reaches the edge of Zayaville's marketplace here. "
		"The cobblestones widen toward the east, where weathered shopfronts "
		"surround the busy square. To the southwest, the road winds away "
		"between the village buildings."
	);

	set_weather(1);

	set_listen(
		"You hear merchants advertising their goods and villagers "
		"haggling over prices."
	);

	add_item(
		"road",
		"The narrow village road widens as it approaches the marketplace."
	);

	add_item(
		"marketplace", "market",
		([
			"look" :
				"Four cobblestone sections form Zayaville's busy marketplace. "
				"Merchants and villagers move between the surrounding shops.\n",

			"smell" :
				"The air carries the mixed scents of food, animals, and smoke.\n",

			"search" :
				"You search around the marketplace but find nothing unusual.\n",
		])
	);

	add_item(
		"cobblestones", "stones", "road",
		([
			"look" :
				"The old cobblestones have been worn smooth by years of carts, "
				"boots, and horses.\n",

			"get" :
				"The cobblestones are firmly embedded in the road.\n",

			"pull" :
				"You tug at one of the stones, but it refuses to move.\n",

			"search" :
				"You search between the cobblestones but find only dirt.\n",
		])
	);

	add_item(
		"shopfronts",
		"Weathered shopfronts face inward toward the marketplace."
	);

	add_item(
		"buildings",
		"The village buildings crowd close to the road."
	);

	set_exits(([
		"east"      : "market_southwest",
		"southwest" : "street_02",
	]));
}