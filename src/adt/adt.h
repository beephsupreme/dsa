#pragma once
#include <cstdint>

/**
 * @class Array
 * @brief A data structure that stores array elements on the heap and provides the utilities to manage them
 */
class Array {
public:
    /**
     * @details By default Array's are created with space for 8 x 32-bit signed integers
     */
    Array();

    /**
     * @details Creates an Array with capacity = size
     * @param size
     * @throw out-of-range
     */
    explicit Array(int32_t size);

    /**
     * @details Creates an Array from an existing Array
     * @param arr
     */
    Array(Array &arr);

    /**
     * @details Deallocates all memory used by the object
     */
    ~Array();

    /**
     * @details Displays Array on stdout
     */
    void display() const;

    /**
     * @details Adds 'element' to the end of the Array
     * @param element
     */
    void append(int32_t element);

    /**
     * @returns The amount of integers that can be stored without resizing
     */
    [[nodiscard]] int32_t getSize() const noexcept;

    /**
     * @returns How many elements are currently in the array
     */
    [[nodiscard]] int32_t getLength() const noexcept;

    /**
     * @details Inserts 'element' into the array at position 'index'
     * @param element
     * @param index
     */
    void insert(int32_t element, int32_t index);

    /**
     * @details Get the element at position 'index'
     * @param index
     * @returns The value located at 'index'
     */
    [[nodiscard]] int32_t get(int32_t index) const;

    /**
     * @details Set the value at position 'index' to 'element'
     * @param element
     * @param index
     */
    void set(int32_t element, int32_t index);

    /**
     * @details Remove the element at position 'index'
     * @param index
     * @returns The value located at 'index'
     */
    int32_t remove(int32_t index);

    /**
     * @details Search for 'element' using linear search if unsorted, binary search if sorted
     * @param element
     * @returns The index where 'element' is located or -1 if not found
     */
    [[nodiscard]] int32_t find(int32_t element);

    /**
     * @details Find the minimum value of the elements in the array
     * @returns The index where 'element' is located or -1 if not found
     */
    [[nodiscard]] int32_t min() const;

    /**
     * @details Find the maximum value of the elements in the array
     * @returns The index where 'element' is located or -1 if not found
     */
    [[nodiscard]] int32_t max() const;

    /**
     * @details Reverses the order of the elements in the array. This is done by allocating heap memory and copying the
     * existing array elements in reverse order. The old array is then deleted.
     * @throw bad_alloc
     */
    void reverse();

    /**
     * @details Find the sum of the values in the array
     * @returns The sum of all elements currently stored in the Array
     */
    int32_t sum();

    /**
     * @details Calculate the average of the current elements in the Array
     * @returns The index where 'element' is located or -1 if not found
     */
    double avg();

    /**
     * @details Sorts the contents of the Array in ascending order
     */
    void sort();

    /**
     * @details Checks if Array is sorted or not
     * @returns a boolean value indicating whether or not the Array is sorted
     */
    bool isSorted();

private:
    int32_t size{};
    int32_t length{};
    int32_t *A{};
    void resize();
    int32_t linear_search(int32_t element);
    int32_t binary_search(int32_t element);
};
