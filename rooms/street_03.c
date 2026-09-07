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

  add_item(
    "road",
    "The narrow village road widens as it approaches the marketplace."
  );

  add_item(
    "marketplace",
    "The marketplace spreads eastward between rows of old shopfronts."
  );

  add_item(
    "cobblestones",
    "The cobblestones have been worn smooth by generations of traffic."
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