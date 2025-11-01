# QMK Firmware

## Project Overview

This is the Quantum Mechanical Keyboard (QMK) firmware, a highly customizable firmware for mechanical keyboards. It is based on the tmk_keyboard firmware and supports a wide range of microcontrollers, including Atmel AVR and ARM. The project is designed to be highly configurable, allowing users to create their own keymaps and custom features.

The firmware is structured around a core set of libraries and a collection of keyboard-specific configurations. Each keyboard has its own directory containing its hardware configuration, keymaps, and other specific settings. The project uses a `Makefile`-based build system and the `qmk` command-line tool to compile the firmware for different keyboards and keymaps.

## Building and Running

To build the firmware for a specific keyboard and keymap, use the `make` command with the following format:

```bash
make <keyboard>:<keymap>
```

For example, to build the firmware for the `lily58/rev1` keyboard with the `default` keymap, you would run:

```bash
make lily58/rev1:default
```

This will generate a `.hex` or `.uf2` file in the root directory of the project, which can then be flashed onto the keyboard's microcontroller.

To flash the firmware, you can use the `qmk flash` command:

```bash
qmk flash -kb <keyboard> -km <keymap>
```

For example:

```bash
qmk flash -kb lily58/rev1 -km default
```

## Development Conventions

The project follows a set of coding conventions for both C and Python, which are documented in the `docs` directory. The codebase is organized by keyboard, with each keyboard having its own dedicated folder. Keymaps are stored in subdirectories within each keyboard's `keymaps` folder.

The firmware is highly modular, with features that can be enabled or disabled in the `rules.mk` file for each keyboard or keymap. This allows for a high degree of customization and optimization.

The project uses Git for version control and encourages contributions from the community through pull requests.

- we want a Changelog.txt file with this format:
  - `YY-MM-DD hh:mm - description'
  - the description should be generated out of the changes since the last commit to git
