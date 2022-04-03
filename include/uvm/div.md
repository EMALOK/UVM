# Div documentation

## Content



## Fields

### uint8* div_start_ptr

It's the start position of the div in this position you can read the div length using little endian encoding

### uint8_t* div_end_ptr

It's the end of the div it still points to the div own data to get the position of the next div you need to use div_next_ptr

### uint8_t* div_content_ptr

It's the start position of the content of the data inside the div

### uint8_t* div_next_ptr

It's the position of the next div (it's calcolated using div_end_ptr + 1)

### uint32_t div_content_size

The size of the content of the div content (it excludes the 4 bytes with the size)

## Methods

### void print(int depth)

This method prints the content like a xml div and check if the character is printable ex.

```xml
<div size = 10>
    64  (d)
    65  (e)
    70  (p)
    73  (s)
    31  (1)
</div>
```
