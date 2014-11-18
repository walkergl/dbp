[DBus (name = "de.dragonbox.PackageDaemon")]
interface DBPBus : Object {
	public abstract string mount(string pkg_id, string user) throws IOError;
	public abstract string u_mount(string id) throws IOError;
	public abstract string register_path(string path, out string error_code) throws IOError;
	public abstract string unregister_path(string path) throws IOError;
	public abstract string mount_point_get(string pkg_id) throws IOError;
	public abstract string path_from_id(string pkg_id) throws IOError;
	public abstract string id_from_path(string path) throws IOError;
	public abstract string[] package_list(string donotcare) throws IOError;
}

DBPBus bus;
