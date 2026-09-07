inherit ARMOUR;

void setup()
{
  set_id("boots");
  set_adj("pair of", "beefy", "leather");

  set_long(
    "This is a pair of extremely beefy leather boots. "
    "A person would need to be very beefy indeed to wear them."
  );

  set_slot("feet");
  set_armour_class(3);
  set_mass(0.3);
  set_value(200);

  set_wearmsg("$N $vput on a pair of beefy leather boots.");
  set_removemsg("$N $vtake off a pair of beefy leather boots.");
}