# Lily58

Lily58 is 6×4+5keys column-staggered split keyboard.

![Lily58_01](https://user-images.githubusercontent.com/6285554/50394214-72479880-079f-11e9-9d91-33fdbf1d7715.jpg)
![2018-12-24 17 39 58](https://user-images.githubusercontent.com/6285554/50394779-05360200-07a3-11e9-82b5-066fd8907ecf.png)
Keyboard Maintainer: [Naoki Katahira](https://github.com/kata0510/) [Twitter:@F_YUUCHI](https://twitter.com/F_YUUCHI)  
Hardware Supported: Lily58 PCB, ProMicro  
Hardware Availability: [PCB & Case Data](https://github.com/kata0510/Lily58)

Make example for this keyboard (after setting up your build environment):

    make lily58:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).



## jorn

### board sea-picro-rp2040
- general help <https://devctrl.blog/posts/the-definitive-guide-to-qmk-compiling-and-flashing-chocofi-with-sea-picro-rp2040/>
- some qmk <https://docs.qmk.fm/platformdev_rp2040>
- general <https://joshajohnson.com/sea-picro/>



### QMK tooling

```bash
qmk compile -kb lily58/rev1 -km jorn -e CONVERT_TO=rp2040_ce
qmk flash  -kb lily58/rev1 -km jorn -e CONVERT_TO=rp2040_ce
```

#### Nuphy
```bash
qmk compile -kb nuphy/air75_v2/ansi -km via
qmk compile -kb nuphy/air75_v2/ansi -km default
qmk config user.keyboard=nuphy/air75_v2/ansi
```

###  test
@#$@$dsfsdf


 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
*                   

schnapper????!!!###***##?!#**ll
....,,,//|||\\\



schnapper????!!!###***##?!#**ll
....,,,//|||\\\



schnapper????!!!###***##?!#**ll
....,,,//|||\\\
Jetzt .lj ljDSAF?!!., .......----,,,,???!!. JK L'     J