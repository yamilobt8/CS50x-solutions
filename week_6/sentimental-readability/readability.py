# TODO

from cs50 import get_string

def count_letters(text):
  """Counts the number of letters in a string."""
  letters = 0
  for char in text:
    if char.isalpha():
      letters += 1
  return letters

def count_words(text):
  """Counts the number of words in a string."""
  words = 1
  for char in text:
    if char == " ":
      words += 1
  return words

def count_sentences(text):
  """Counts the number of sentences in a string."""
  sentences = 0
  for char in text:
    if char in [".", "?", "!"]:
      sentences += 1
  return sentences

def main():
  """Calculates the Flesch-Kincaid readability grade of a text."""
  text = get_string("Text: ")
  letters = count_letters(text)
  words = count_words(text)
  sentences = count_sentences(text)

  L = float(letters) / float(words) * 100
  S = float(sentences) / float(words) * 100

  GRADE = round(0.0588 * L - 0.296 * S - 15.8)

  if GRADE < 1:
    print("Before Grade 1")
  elif GRADE >= 16:
    print("Grade 16+")
  else:
    print("Grade {}".format(GRADE))

if __name__ == "__main__":
  main()