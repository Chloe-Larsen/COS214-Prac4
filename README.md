# COS 214 Practical 4 — TaskForge: Shipping Logistics

A C++ simulation of a shipping-logistics system, built to demonstrate four
Gang-of-Four design patterns working together as one running application.

## Team

|Name|Student no.|GitHub|
|-|-|-|
|*(Chloe)*|*25004141*|@Chloe-Larsen|
|*(Lee)*|*25019385*|@lee-codes012|
|*(Jayden)*|*??*|@*Jaytad05*|

## Domain

Cargo is organised as a recursive hierarchy: a **Freight** ship holds
**Containers** and **Pallets**, which in turn hold **Parcels**. Parcels can be
wrapped with optional handling responsibilities (refrigeration, hazmat,
insurance), and each parcel moves through a shipping **lifecycle** from booking
to delivery, including a customs detour.

## Design patterns

|Pattern|Role|Classes|
|-|-|-|
|**Composite**|part–whole cargo hierarchy|`ShippingUnit` (component), `Parcel` (leaf), `CargoGroup` + `Container`/`Pallet`/`Freight` (composites)|
|**State**|parcel lifecycle|`ShippingState` (+ `Booked`, `InTransit`, `CustomsHold`, `ClearedCustoms`, `Delivered`)|
|**Decorator**|optional runtime responsibilities|`ShipmentType` (base) + `Hazmat`, `Refrigerated`, `Insured`|
|**Iterator**|traversal without exposing the structure|`Inspection` (interface) + `Manifest` (pre-order) and `CustomsAudit` (post-order)|

## Traversal-modification policy

Both iterators use **snapshot traversal**: the structure is flattened into an
internal list when the iterator is created. A structural change made after an
iterator exists (e.g. adding a parcel) does **not** affect that in-progress
traversal — callers who want the change create a fresh iterator. This keeps
every traversal safe and predictable. Demonstrated live in Scenario 2.

## Build \& run

```bash
make            # compile with -Wall -Wextra -pedantic -std=c++11
make run        # build and run the demonstration
./taskforge     # run directly
make clean      # remove build artifacts
```

## Debugging \& memory (Task 5)

```bash
make debug      # launch the program under GDB
make valgrind   # full leak check
# or directly:
valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```

The final application performs a single clean cascade of deletions from the
root `Freight` object and reports no leaks.

## Docker

Reproduce the full environment (g++, make, gdb, valgrind) without installing
anything on the host:

```bash
docker build -t taskforge .
docker run --rm taskforge                 # runs the demonstration
docker run --rm -it taskforge bash        # shell for gdb / valgrind
```

## Repository layout

```
import/   header files
src/      implementation files
main.cpp  demonstration (two runtime scenarios)
resources/     design portfolio (UML, diagrams, PDF)
Makefile  build rules
Dockerfile
```

