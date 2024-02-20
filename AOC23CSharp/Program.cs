// See https://aka.ms/new-console-template for more information
using AOC23CSharp.Day1;
using System.Diagnostics;

Console.WriteLine("Hello, World!");

Stopwatch stopwatch = Stopwatch.StartNew(); // Start timing

// Day 1
var day1 = new CalibrationDocument();
day1.processFile(@"..\..\..\Day1\data.txt");

Console.WriteLine(day1.sum);

stopwatch.Stop();
Console.WriteLine($"Execution Time: {stopwatch.ElapsedMilliseconds} ms");