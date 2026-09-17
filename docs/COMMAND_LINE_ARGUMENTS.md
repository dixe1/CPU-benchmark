## COMMAND LINE ARGUMENTS

```bash
./Benchmark [type] [cores]
```

### Options:

| Argument | Wartości                        |
|----------|---------------------------------|
| `type`   | `--benchmark`, `--stress-test`  |
| `cores`  | `--multi-core`, `--single-core` |

> [!IMPORTANT]
> `type` has to be typed **first**, `cores` **second**.

### Examples:

```
./Benchmark --benchmark   --multi-core
./Benchmark --stress-test --multi-core
./Benchmark --benchmark   --single-core
./Benchmark --stress-test --single-core
```

> If you pass an invalid argument, the program will exit.  
> If you pass more than two arguments the program will start like with no arguments