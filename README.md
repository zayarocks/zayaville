# Zayaville
Zayaville is a very basic mudlib running on FluffOS. Highly inspired by the LPC for Dummies books by Drakkos. In fact, all of the code is more or less identical, just with the word "Zaya" all over it. (Clever, isn't it?)

All files reside in the domain folder located at ``lib/domain/zayaville``. If you don't want to live in Zayaville, make whatever 'ville you'd like. 

The code from the book has been modified to work with LIMA mudlib, skipping over the Discworld-specific items entirely.

**NOTE:** There is no reason to copy/paste the below code. It's only for reference. The repo contains the complete code for Zayaville.

## LPC for Dummies: Book 1
This guide assumes a certain proficiency at Unix administration and programming in C. However, the book itself 

### My First (and Second) Room(s)

### rooms/street_01.c
Edit rooms/street_01.c. The following code demonstrates how to set the initial descriptive text for the room, as well as the weather and any items. 
*The active working directory should be your personal domain folder.*

```c
void setup() 
{
	/* Descriptive room text */
	set_area("zayaville");

	set_brief("Simple Village Road");

	set_long(
		"This is a simple road leading to a simple village. There is "
		"very little of any excitement about it, except that it represents "
		"your first steps toward becoming a creator!"
	);

	set_weather(1);

	/* Add any "discoverable" items here. */
	add_item(
		"village",
		"The village is simple, but beautiful because of it."
	);

	add_item(
		"road",
		"The road passes beneath you on its way toward the village."
	);

	/* Navigate to a second room */
	set_exits(([
	"northeast" : "street_02",
	]));

}
```

rooms/street_02.c
```c
inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Simple Village Road");

  set_long(
	"This is a little way along the path to the village of "
	"Zayaville. The path continues northeast toward the rickety "
	"buildings of the market square. To the southwest, the path "
	"winds away from what passes as civilization here."
  );

  set_weather(1);

  set_exits(([
	"southwest" : "street_01",
  ]));
}
```
Note the reverse exit going back to street_02. 


To see the updated room, run the following commands on the MUD:
```bash
update rooms/street_01.c
goto rooms/street_01.c
look
look at village
look at road
```

(Not all nouns from the description need to be actual items in the room. However, doing so certainly helps with immersion.)


### My First Area
Create a skeleton room and copy it:
rooms/market_01.c
```c
inherit OUTDOOR_ROOM;

void setup()
{
  set_area("zayaville");
  set_brief("Market");
  set_long("This is a section of the market.");
  set_weather(1);
}
```
To copy:
```bash
cp rooms/market_01.c
```

**Add the following exits:**
rooms/market_southwest.c
```c
set_exits(([
  "north"     : "market_northwest",
  "east"      : "market_southeast",
  "west"      : "street_03",
  "northeast" : "market_northeast",
]));
```

rooms/market_southeast.c
```c
set_exits(([
  "north"     : "market_northeast",
  "west"      : "market_southwest",
  "northwest" : "market_northwest",
]));
```

rooms/market_northeast.c
```c
set_exits(([
  "south"     : "market_southeast",
  "west"      : "market_northwest",
  "southwest" : "market_southwest",
]));
```

rooms/market_northwest.c
```c
set_exits(([
  "south"     : "market_southwest",
  "east"      : "market_northeast",
  "southeast" : "market_southeast",
]));
```

To update the rooms:
```bash
update rooms/*
```

At this point you should have a completely navigatable (albeit small) MUD area! 

### Building The Perfect Beast

Here is the code for our first NPC:
```c
// file: chars/captain_beefy.c
inherit ADVERSARY;

// idle 
inherit M_ACTIONS;

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
	
}
```

To make Captain Beefy magically appear:
```bash
update chars/*
clone chars/captain_beefy.c
```

To get him to talk back, add this to the top...
```c
inherit M_TRIGGERS;
```

...and this somewhere in the ``setup`` function.
```c
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
```

Update Beefy again. He will now respond to the following words: "hello", "hi", kill", "murder".

Now we can dress him up and give him a couple objects:
```c
set_wearing("/domains/std/armour/fullplate");
set_wielding("/domains/std/weapon/sword");

set_objects(([
  "/domains/std/consumable/bandage" : 2,
  "/domains/std/consumable/peanuts" : 1,
]));
```

Take a look at this handsome creature:
```bash
look at beefy
look at beefy's sword
inventory of beefy
```

Now let's make him fiesty!
```c
/* chars/captain_beefy.c */
varargs void attacked_by(object attacker, int take_a_swing)
{
  string *reactions = ({
    "$N $vcry to $t, \"Oh please, not again!\"",
    "$N $vshout at $t, \"I don't have medical insurance!\"",
    "$N $vplead with $t for mercy.",
  });

  if (!query_target())
    targetted_action(choice(reactions), attacker);

  ::attacked_by(attacker, take_a_swing);
}
```
Place this code after the ``setup`` function. Update, clone, and 'kill' to see Beefy's reaction.


### Hooking Up
Adding an NPC to a room onload is similar to adding any other object:
```
set_objects(([
  "../chars/captain_beefy" : 1,
]));
```

### Back To The Beginning
Let's expand the marketplace object in ``street_03.c``` to make it more interactive. Replace the generic ``add_item`` code with the following.

```c
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
```

We can do the cobblestones too: 
```c
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
```

The following is LIMA's convention for setting a sound in a room. It replaces the 'listen' embedded into the ``add_item`` function. 
```c
set_listen(
  "You hear merchants advertising their goods and villagers "
  "haggling over prices."
);
```

### Now That We're An Item
We are not limited to the default items. We can expand them into our own custom items. 
```c
/* file: items/beefy_boots.c */
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
```

Go back to Captain Beefy and add the new item: 
```c
set_wearing("../items/beefy_boots");
```
Update Beefy and reclone. His boots should now be beefy.

Now we can give him a little bit of bling.
```c
/* items/beefy_ring.c a*/
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
```


### An Inside Job
Let's head inside by adding some indoor rooms. This example creates a little shop. 

```c
/* rooms/mysterious_room.c */
inherit INDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Mysterious Room");

  set_long(
    "This is a mysterious room. The oppressive atmosphere hints "
    "mysteriously at some deeper mystery."
  );

  add_item(
    "mystery",
    "You cannot see the mystery, which only makes it more mysterious."
  );

  add_item(
    "darkness",
    "The darkness seems almost independent of the room's actual lighting."
  );

  set_listen(
    "The room emits a faint and deeply mysterious hum."
  );

  set_exits(([
    "south" : "market_northwest",
  ]));
}
```

Add a matching exit to ``market_northwest.c``.
```c
set_exits(([
  "south"     : "market_southwest",
  "east"      : "market_northeast",
  "southeast" : "market_southeast",
  "north"     : "mysterious_room",
]));
```

Update the rooms, then enter the northwestern marketplace and travel north until you hit the ``mysterious_room``. 
```c
/* items/mysterious_door.c */
/* file: items/mysterious_door.c */
inherit DOOR;

void setup(string direction, string destination)
{
  set_id("door");
  set_adj("mysterious", "wooden");

  set_long(
    "The mysterious wooden door hints at riches and mystery within."
  );

  set_sibling_ident("zayaville mysterious door");
  set_door_direction(direction);
  set_door_destination(destination);
  set_closed(1);

  set_flag(ATTACHED);
}
```

Now let's add a mysterious door to our mysterious room. Remove the north exit from ``rooms/market_northwest.c`` and add the new door item instead.
```
set_objects(([
  "../items/mysterious_door" : ({ "north", "mysterious_room" }),
]));
```

Here's the door code to add to ``mysterious_room``. It replaces the ``set_exits`` function.
```
set_objects(([
  "../items/mysterious_door" : ({ "south", "market_northwest" }),
]));
```

Now we can add our shop, Stabby Joe's Emporium of Wonder. Don't worry, we'll make the shopkeeper next. 
```
/* file: rooms/stabby_joe.c */
inherit INDOOR_ROOM;

void setup()
{
  set_area("zayaville");

  set_brief("Stabby Joe's Emporium of Wonder");

  set_long(
    "This is Stabby Joe's Emporium of Wonder, where he sells "
    "wonderful things. He also stabs people."
  );

  add_item(
    "emporium", "shop",
    "The emporium is packed with strange and wonderful merchandise."
  );

  set_exits(([
    "south" : "market_northeast",
  ]));
}
```

Update ``market_northeast.c`` exits to point to Stabby's: 
```c
set_exits(([
  "south"     : "market_southeast",
  "west"      : "market_northwest",
  "southwest" : "market_southwest",
  "north"     : "stabby_joe",
]));
```

### Dysfunctional Behavior
```
```

### Going Loopy
```
```

### Arrays, You say?
```
```

### Hooray for Arrays
```
```

### Mapping It Out
```
```

### So Long
```
```
