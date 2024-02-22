namespace CSharp.Day1.Part2
{
    internal class CalibrationDocument
    {
        public int sum { get; private set; } = 0;

        private static readonly Dictionary<string, int> numberStrings = new Dictionary<string, int>
        {
            {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
            {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
        };

        private int? ExtractTextualNumberFromLine(string line)
        {
            foreach (var pair in numberStrings)
            {
                if (line.Contains(pair.Key))
                {
                    return pair.Value;
                }
            }
            return null;
        }

        private int ExtractNumberFromLine(string line)
        {
            int? first = null, last = null;

            for (int i = 0; i < line.Length; i++)
            {
                if (char.IsDigit(line[i]))
                {
                    if (!first.HasValue)
                        first = line[i] - '0';
                    else
                        last = line[i] - '0';
                }
                else
                {
                    var extractedTextNumber = ExtractTextualNumberFromLine(line[i..]);
                    if (extractedTextNumber is not null)
                    {
                        if (!first.HasValue)
                            first = extractedTextNumber;
                        else
                            last = extractedTextNumber;
                        break; // Assuming one textual number per line
                    }
                }
            }

            if (!first.HasValue)
                return 0;
            else if (!last.HasValue)
                return first.Value * 10 + first.Value;

            return first.Value * 10 + last.Value;
        }

        public void processFile(string path)
        {
            using (var reader = new StreamReader(path))
            {
                string? line;
                while ((line = reader.ReadLine()) is not null)
                {
                    sum += ExtractNumberFromLine(line.Trim());
                }
            }

        }
    }
}
