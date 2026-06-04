#!../../bin/darwin-aarch64/sysmon

#- SPDX-FileCopyrightText: 2005 Argonne National Laboratory
#-
#- SPDX-License-Identifier: EPICS

#- You may have to change sysmon to something else
#- everywhere it appears in this file

#< envPaths

## Register all support components
dbLoadDatabase "../../dbd/sysmon.dbd"
sysmon_registerRecordDeviceDriver(pdbbase) 

## Load record instances
dbLoadRecords("../../sysmonApp/Db/sysmon.db")
iocInit()

## Start any sequence programs
#seq sncsysmon,"user=ahdo1293"
