#pragma once
#include <cstdint>

/**
 *  @brief Array data structure that manages array elements on the heap.
 */
class Array {
 public:
  /**
   * @brief Default Constructor
   */
  Array();

  /**
   * @brief Construct Array with a specific size.
   * @param size
   */
  explicit Array(int32_t size);

  /**
   * Array copy-constructor
   * @param c
   */
  Array(Array &c);

  /**
   * @brief default destructor
   */
  ~Array();

  /**
   * @brief Display array contents
   */
  void display() const;

  /**
   * @brief add element to end of the array
   * @param element
   */
  void append(int32_t element);

  /**
   * @brief get size of the array
   * @return capacity of array
   */
  [[nodiscard]] int32_t getSize() const;

  /**
   * @brief get the length of the array
   * @return how many elements are in the array
   */
  [[nodiscard]] int32_t getLength() const;

  /**
   * @brief insert element in array position index
   * @param element
   * @param index
   */
  void insert(int32_t element, int32_t index);
  [[nodiscard]] int32_t get(int32_t index) const;
  void set(int32_t element, int32_t index);
  int32_t remove(int32_t index);
  [[nodiscard]] int32_t find(int32_t element);
  [[nodiscard]] int32_t min() const;
  [[nodiscard]] int32_t max() const;
  void reverse();
  int32_t sum();
  double avg();
  void sort();
  bool isSorted();
 private:
  int32_t size{};
  int32_t length{};
  int32_t *A{};
  void resize();
  int32_t linear_search(int32_t element);
  int32_t binary_search(int32_t element);
};
