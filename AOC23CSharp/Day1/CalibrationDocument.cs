namespace AOC23CSharp.Day1
{
    internal class CalibrationDocument
    {
        public int sum { get; private set; } = 0;

        private int extractNumberFromLine(string line)
        {
            var digits = line.Where(char.IsDigit).ToArray();

            if (digits.Length >= 2)
            {
                return int.Parse($"{digits.First()}{digits.Last()}");
            }
            else if (digits.Length == 1)
            {
                return int.Parse($"{digits.First()}{digits.First()}");
            }
            else return 0;
        }

        public void processFile(string path)
        {
            using (var reader = new StreamReader(path))
            {
                string? line;
                while ((line = reader.ReadLine()) is not null)
                {
                    sum += extractNumberFromLine(line);
                }
            }

        }
    }
}
