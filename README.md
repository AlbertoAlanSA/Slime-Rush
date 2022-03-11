# _Slime Rush_
 _Slime Rush_ is a little NDS game for the "video game consoles and devices" subject. It's programmed in C handeling the NDS console's input/output system. In particular, this game is	an endless runner in which you manage a little slime who has to doge fences and ward off flys.
 
![image](https://user-images.githubusercontent.com/83225413/157930568-402d0e78-da2d-4dfc-ab0a-a9326037b20d.png "Slime Rush screen tile")

## Why _Slime Rush_?

The main idea was to make an easy and realxing game, but not boring. Because of that, I opt for a friendly, non-threatening atmosphere (even though there are enemies), in which the only thing you have to worry about is to dodge a few fences and defend yourself from flies to overcome your previous score.

![image](https://user-images.githubusercontent.com/83225413/157930945-6b3bd275-481f-426b-83d5-2bc341755076.png)


## How do you play?

To play the game you need an emulator, since it's a NDS console game (you must execute the  Juego.nds file). I've use the _WinDS Pro_ one in the _No$gba_ mode. (Link to the emulator: https://windsprocentral.blogspot.com/). 

The controls, like the game, are simple: the up and down keys will be used to go in these directions, while with A and B we will put a red or blue shield, respectively. We must dodge the fences and use the shield of the right color at the right time to defend you from flies. As time progresses, so will the score, however, as night falls, it will become more dangerous.

## Objective

With this project, the goal was to create an artistically enjoyable as well as randomly generated game.

### Floor generation

According to a timer, the floor is generated randomly on the last line of the screen and, when the floor moves, it will appears. This is generated following the following criteria: 
- Generate in the ground.
- Leave a gap of minimum 2 tiles to pass.
- Having the fences are well placed, according to the corresponding fence model (there are 4 possible).


### Fly generation

Flies are generated randomly on the ground, and by checking your position against theirs, they will move to chase you. However, you can defend against them with a shield of the right color (which increases the hitbox by 1).


### Night-day cycle

In the game, the night is more dangerous: one more fly will emerge. This cycle is marked by the sun (and the moon) seen in the sky. Gradually move to reach the horizon and change the cycle.

## Music

There is background music as well as sound effects for the appearance of a fly, when you move, when you lose and when you are hit.

## Lifes

You have three lives. In case you are hit three times, you lose all of them and you lose the game. However, once you get hit, you gain 1 second of invulnerability in which you cannot be hurted again.

## Gameplay

Gameplay:

https://user-images.githubusercontent.com/83225413/157934542-e2ab67a7-53d2-456e-8ba5-c2ade1ae874b.mp4

