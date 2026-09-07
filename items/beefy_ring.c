inherit ARMOUR;

void setup()
{
  set_id("ring");
  set_adj("heavy", "gold", "beefy");

  set_long(
    "This is a heavy gold ring made for Captain Beefy. "
    "A tiny shield has been engraved into its broad face."
  );

  set_slot("hand");
  set_armour_class(1);
  set_mass(0.1);
  set_value(500);

  set_wearmsg("$N $vslide a heavy gold ring onto one finger.");
  set_removemsg("$N $vpull a heavy gold ring from one finger.");
}