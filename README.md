# Validation of vulnerabilities in memory access

## Test Categories

---

### Memory

**1. null dereference**

**2. Buffer overflow**

**3. Memory corruption**

**4. Double free**

**5. Use after free**

---

### 2. Integers

**1. Overflow**

**2 Underflow**

---

### 3. Concurrency

**- Not in scope**

# Steps

docker build -t splode-image .

./splode.sh --source-file [sut_file_location] --rule-file [config_file_location]

Then, the tool will create a
[file_where_sut_is]\_[sut_name]\_splode.c file.
