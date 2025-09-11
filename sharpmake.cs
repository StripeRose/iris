using System.IO;

[module: Sharpmake.Include("atrium/engine/sharpmake.cs")]
[module: Sharpmake.Include("iris/sharpmake.cs")]

namespace Iris
{
	[Sharpmake.Generate]
	public class IrisSolution : Atrium.Solution
	{
		public IrisSolution()
		{
			Name = "Iris";
		}

		public override void ConfigureAll(Sharpmake.Solution.Configuration conf, Sharpmake.Target target)
		{
			base.ConfigureAll(conf, target);
			conf.SolutionPath = "[solution.SharpmakeCsPath]";

			conf.AddProject<IrisExecutable>(target);
		}
	}
}

public static class Main
{
	[Sharpmake.Main]
	public static void SharpmakeMain(Sharpmake.Arguments arguments)
	{
		FileInfo fileInfo = Sharpmake.Util.GetCurrentSharpmakeFileInfo();

		Atrium.Configuration.SolutionDirectory = fileInfo.DirectoryName;
		Atrium.Configuration.BuildDirectory = Path.Combine(
			fileInfo.DirectoryName,
			"build"
		);
		
		arguments.Generate<Iris.IrisSolution>();
	}
}