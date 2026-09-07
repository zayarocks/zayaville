inherit ADVERSARY;
inherit M_ACTIONS;
inherit M_TRIGGERS;

void setup()
{
  ::setup();

  set_name("beefy");
  add_id("captain");

  set_proper_name("Captain Beefy");
  set_in_room_desc("Captain Beefy stands here, looking nervous.");

  set_long(
    "Captain Beefy is a former military officer who retired after being "
    "stabbed in the face by a marauding adventurer. He now lives in "
    "Zayaville, hoping to enjoy a quiet life before someone murders him "
    "for his shoes."
  );

  set_gender(1);
  set_race("human");
  set_level(10);

  set_actions(
    10,
    ({
      "say Please don't hurt me.",
      "cower",
      "say Here come the drums!",
      "stare",
    })
  );

  add_pattern(
    "%s says: %s.",
    (: $2 ? $2 : 0 :),
    0,
    "beefy_speech"
  );

  add_sub_pattern(
    "beefy_speech",
    "%shello%s",
    "say Er, hello. Please don't kill me."
  );

  add_sub_pattern(
    "beefy_speech",
    "%shi%s",
    "say Er, hello. Please don't kill me."
  );

  add_sub_pattern(
    "beefy_speech",
    "%skill%s",
    "say No, please no. I beg you!"
  );

  add_sub_pattern(
    "beefy_speech",
    "%smurder%s",
    "say No, please no. I beg you!"
  );

  set_wearing("/domains/std/armour/fullplate");
  set_wielding("/domains/std/weapon/sword");

  set_objects(([
    "/domains/std/consumable/bandage" : 2,
    "/domains/std/consumable/peanuts" : 1,
  ]));
}

void under_attack_by(object attacker)
{
  string *reactions = ({
    "$N $vcry to $t, \"Oh please, not again!\"",
    "$N $vshout at $t, \"I don't have medical insurance!\"",
    "$N $vplead with $t for mercy.",
  });

  targetted_action(choice(reactions), attacker);
}