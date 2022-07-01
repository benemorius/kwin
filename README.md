This branch holds some work-in-progress patches that add a few things to the scripting API for use with [bismuth](https://github.com/benemorius/bismuth), a tiling addon implemented as a kwin script.

* emit a `workspaceDestroyed` signal when kwin is exiting (so we can know to keep the window state information and restore everything after kwin restarts)
* (TODO) expose the read/write property `window.hidden` (so we can implement changing virtual desktops on a per-monitor basis)
* (TODO) yet to be determined
