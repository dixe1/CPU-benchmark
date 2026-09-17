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
> `type` have to be typed **first**, `cores` **secound**.

### Examples:

```
./Benchmark --benchmark   --multi-core
./Benchmark --stress-test --multi-core
./Benchmark --benchmark   --single-core
./Benchmark --stress-test --single-core
```