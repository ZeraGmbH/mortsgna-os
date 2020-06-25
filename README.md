# zera-os
This repo combines all meta layers of the OE image

## Clone Project

in your terminal:

```
git clone <repo> 
cd /<path>/<to>/<repo>
git submodule update --init --recursive
git submodule update --remote
```

## Setup Project

go to mortsgna-os and call 

```
scritps/init.sh
```

The script will ask you where to build. You will need at least 512GB of free space to 
build. The script will also ask, if you want to apply the patches stored in folder patches.
If you type yes, the script will call the applypatches script. Only patches added to this script will 
be applyed.

You can also call the script with command line paramters. This is for example usefull with autobuilders like jenkins.

```
scripts/init.sh -b <buildpath> -p (yes/no)
```

The -p option with "yes" applys patches, "no" does not apply patches.


Befor you can build go to the oe-core folder.
add the btibake path with following command:

```
source ../oe/environment-oecore.sh
```

## Add Layer

To add a subproject first add it in git with following command:

```
git submodule add -b <branch> git@github.com:ZeraGmbH/<project> <path>/<project>
```

for example:


```
git submodule add -b master git@github.com:ZeraGmbH/vf-declarative-gui.git guis/vf-declarative-gui
```

check if the submodule appears in .gitmodules.

## Remove Layer


    - Delete the section referring to the submodule from the .gitmodules file
    - Stage the changes via git add .gitmodules
    - Delete the relevant section of the submodule from .git/config.
    - Run git rm --cached path_to_submodule (no trailing slash)
    - Run rm -rf .git/modules/path_to_submodule
    - Commit the changes with ```git commit -m "Removed submodule "
    - Delete the now untracked submodule files rm -rf path_to_submodule





