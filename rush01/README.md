# ft_monitor
System monitor project at 42.

### Config
```
OS
CPU
network
disks
```
Case insensitive, contains an ordered list seperated by
newlines ("\n") read from `monitor.config` at launch.
invalid modules are ignored.
if there are no valid modules fallback on a defaults
which are also used when there is no config.

## IMonitorModule
* name - i.g "CPU"
* type - one of {Chart, Table, String}
* update - Update internal date, for example to read the new CPU usage.
* get - Returns internal data in a container such as a `List()`

## IMonitorDisplay
Relies on `ImonitorModule.type` to
know how to render a module, interface will depend on
the limitations of *Qt* as it is less felxible than
*ncurses*
