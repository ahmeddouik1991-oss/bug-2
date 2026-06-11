wenige mswenige ms# Protokoll – EPICS aSub SCAN Übungsaufgabe

**Name:** Ahmed Douik  
**Matrikelnummer:** 108335  
**Modul:** Echtzeitsysteme (B18) – 3. Semester – BHT Berlin / FHI  
**Datum:** 04.06.2026  

---

## 1. Messung

Die Aufzeichnung erfolgte mit:

```bash
camonitor -t SYS:LOAD1 SYS:UPTIME | tee camonitor.log
```

Die Messung wurde über mehr als 30 Sekunden durchgeführt. Die erzeugten PVs wurden zusätzlich mit `caget` überprüft.

---

## 2. Auswertung der Periode

Aus den Zeitstempeln der camonitor-Aufzeichnung wurden die Zeitabstände zwischen zwei aufeinanderfolgenden Aktualisierungen bestimmt.

| Kennzahl                    | Wert       |
|-----------------------------|------------|
| Sollperiode                 | 2,000 s    |
| Gemessene mittlere Periode  | ca. 2,000 s |
| Maximale Abweichung         | wenige ms     |
| Jitter                      | gering   |

Die Messwerte zeigen eine regelmäßige Aktualisierung im Abstand von etwa 2 Sekunden. Die gemessene mittlere Periode entspricht damit dem konfigurierten SCAN-Wert.

---

## 3. Diskussion
Die PVs liefern gültige Werte und werden regelmäßig aktualisiert. Die Messung zeigt, dass die Aktualisierungsperiode ungefähr 2 Sekunden beträgt und damit dem konfigurierten SCAN-Wert entspricht.

Der IOC arbeitet korrekt und die erzeugten PVs können mit caget und camonitor überwacht werden.

---

## Fazit

Der EPICS-IOC wurde erfolgreich implementiert und getestet. Alle geforderten PVs liefern gültige Werte. Das SCAN-Verhalten entspricht dem konfigurierten Wert von 2 Sekunden und die gemessenen Abweichungen liegen im erwarteten Bereich.
