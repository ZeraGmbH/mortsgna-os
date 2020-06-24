# zera-os
This repo combines all meta layers of the OE image

This repo is not useable yet.

## Add Subproject to SuperBuild

### Add to git 
To add a subproject first add it in git with following command:

```
git submodule add -b <branch> git@github.com:ZeraGmbH/<project> <path>/<project>
```

for example:


```
git submodule add -b master git@github.com:ZeraGmbH/vf-declarative-gui.git guis/vf-declarative-gui
```

check if the submodule appears in .gitmodules.
